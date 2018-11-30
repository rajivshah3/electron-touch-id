{
  "targets": [
    {
      "target_name": "electron-touch-id",
      "sources": [
        "ElectronTouchID/interface.cc"
      ],
      "cflags+": ["-std=c++11"],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      "link_settiings": {
        "libraries": [
          "$(pwd)/ElectronTouchID/out/ElectronTouchID.framework"
        ],
      },
    }
  ]
}
