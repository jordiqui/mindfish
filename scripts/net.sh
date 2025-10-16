#!/bin/sh

wget_or_curl=$( (command -v wget > /dev/null 2>&1 && echo "wget -qO-") || \
                (command -v curl > /dev/null 2>&1 && echo "curl -skL"))


sha256sum=$( (command -v shasum > /dev/null 2>&1 && echo "shasum -a 256") || \
             (command -v sha256sum > /dev/null 2>&1 && echo "sha256sum"))

if [ -z "$sha256sum" ]; then
  >&2 echo "sha256sum not found, NNUE files will be assumed valid."
fi

get_nnue_filename() {
  grep "$1" evaluate.h | grep "#define" | sed "s/.*\(nn-[a-z0-9]\{12\}.nnue\).*/\1/"
}

validate_network() {
  # If no sha256sum command is available, assume the file is always valid.
  if [ -n "$sha256sum" ] && [ -f "$1" ]; then
    if [ "$1" != "nn-$($sha256sum "$1" | cut -c 1-12).nnue" ]; then
      rm -f "$1"
      return 1
    fi
  fi
}

fetch_network() {
  _filename="$(get_nnue_filename "$1")"

  if [ -z "$_filename" ]; then
    >&2 echo "NNUE file name not found for: $1"
    return 1
  fi

  if [ -f "$_filename" ]; then
    if validate_network "$_filename"; then
      echo "Existing $_filename validated, skipping download"
      return 0
    else
      echo "Removing invalid NNUE file: $_filename"
      rm -f "$_filename"
    fi
  fi

  if [ -z "$wget_or_curl" ]; then
    >&2 printf "%s\n" "Neither wget or curl is installed." \
          "Install one of these tools to download NNUE files automatically."
    exit 1
  fi

  for url in \
    "https://tests.stockfishchess.org/api/nn/$_filename" \
    "https://github.com/official-stockfish/networks/raw/master/$_filename"; do
    echo "Downloading from $url ..."
    tmp_file="$_filename.tmp"
    rm -f "$tmp_file"
    if $wget_or_curl "$url" > "$tmp_file"; then
      mv "$tmp_file" "$_filename"
      if validate_network "$_filename"; then
        echo "Successfully validated $_filename"
        return 0
      else
        echo "Downloaded $_filename is invalid"
        rm -f "$_filename"
      fi
    else
      echo "Failed to download from $url"
      rm -f "$tmp_file"
    fi
  done

  # Download was not successful in the loop, warn the user but don't fail hard.
  >&2 echo "Failed to download $_filename"
  return 0
}

fetch_network EvalFileDefaultNameBig && \
fetch_network EvalFileDefaultNameSmall
