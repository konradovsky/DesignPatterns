#!/bin/bash

case $1 in 
    --observer )       
        PROJ_NAME="Observer"
        FOLDER_NAME="02. Observer Pattern" ;;
    --test )       
        PROJ_NAME="Test" ;;
    * ) echo 'Unsupported project nam; use: --observer' exit 1
esac

#modify premake file
sed -i '' "s/project.*/project \"$PROJ_NAME\"/" ./vendor/premake5.lua
#copy into right directory
cp ./vendor/premake5.lua ./"$FOLDER_NAME"/C++/

#cp ./vendor/premake5.lua ./02.\ Observer\ Pattern/C++/

DUPA="Debug\/$PROJ_NAME\","

sed -i '' "s/Debug.*/$DUPA/" ./.vscode/launch.json
