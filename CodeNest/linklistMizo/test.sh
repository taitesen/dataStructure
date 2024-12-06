#!/usr/bin/env bash

GITHUB_USERNAME="taitesen"
REPO_NAME="dataStructure"
DIRECTORY="linklistMizo"

git clone --dept 1 --filter=blob:none --sparse https://github.com/$GITHUB_USERNAME/$REPO_NAME.git

cd $REPO_NAME || exit

git sparse-checkout set $DIRECTORY

wait 2

cd dataStructure

cd linklistMizo

./run

