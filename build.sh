#!/usr/bin/env sh


RUNTIME="docker run --rm -it --user $(id -u):$(id -g) -w /qmk_firmware -v $(pwd)/../qmk_firmware:/qmk_firmware -v $(pwd)/builds:/qmk_firmware/.build -v $(pwd)/custom36:/qmk_firmware/keyboards/custom36 -v $(pwd)/bm40hsrgb:/qmk_firmware/keyboards/kprepublic/bm40hsrgb/keymaps/custom -v $(pwd)/xd75:/qmk_firmware/keyboards/xiudi/xd75/keymaps/custom -e ALT_GET_KEYBOARDS=true -e SKIP_GIT='$SKIP_GIT' -e MAKEFLAGS='$MAKEFLAGS' qmkfm/qmk_cli"

if [[ $1 == "bm40hsrgb" ]]; then
  $RUNTIME make kprepublic/bm40hsrgb:custom
elif [[ $1 == "xd75" ]]; then
  $RUNTIME make xiudi/xd75:custom
elif [[ $1 == "custom36" ]]; then
  $RUNTIME make custom36:default
else
  $RUNTIME bash
fi
