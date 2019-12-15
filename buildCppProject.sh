#!/bin/bash

case $1 in 
    --observer )       
        PROJ_NAME="Observer"
        FOLDER_NAME="02. Observer Pattern"
        #this is terrible but whatever
        FOLDER_NAME_SPEC="cd\ .\/02.\\\ Observer\\\ Pattern" ;;
    * ) echo 'Unsupported project name! use: --observer'
esac

if [ -z "$PROJ_NAME" ]
then
    exit 1
fi

#modify premake file
sed -i '' "s/project.*/project \"$PROJ_NAME\"/" ./cpp/premake5.lua
#modify build script
sed -i '' "s/cd \..*/$FOLDER_NAME_SPEC\/C++/" ./cpp/jebacVSCode.sh

#copy premake into right directory
cp ./cpp/premake5.lua ./"$FOLDER_NAME"/C++/

#set build task in vs code
DUPA="Debug\/$PROJ_NAME\","
sed -i '' "s/Debug.*/$DUPA/" ./.vscode/launch.json
