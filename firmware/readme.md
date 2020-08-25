## To Build With Docker

First install docker desktop. Follow directions [here](https://docs.docker.com/docker-for-windows/install/) for windows.

powershell command (in windows):

```PowerShell
docker build -t qmk-builder .

docker run --rm -it `
    --mount type=bind,source="${PWD}/build",target="/qmk_firmware/.build" `
    --mount type=bind,source="${PWD}/lily58",target="/qmk_firmware/keyboards/lily58" `
    qmk-builder make lily58/glowEnc:orvisevans
```

And wait. It's slow the first time. It's faster after the first time thanks to docker caching. Firmware will show up in build folder when it's done.

## Pin Names Notes

Mostly a note for myself, as this confused me greatly.

Pins are not defined by their arduino names, but by the actual chip names. For example, the arduino pin "TX" is chip pin "PD3" and in programming, drop all but the last letter and number: "D3"
