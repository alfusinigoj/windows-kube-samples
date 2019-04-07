# ISAPI Module

Here is a dockerized 64-bit ISAPI module.

A VS 2019 VC++ is present in the PKSISAPI directory, but the 64-bit .DLL (`PKSISAPI.dll`) is included in this directory for convenience.

You can text the module by
```
curl http://<CONTAINER PATH>/isapi/PKSISAPI.dll
```

## Dockerfile

The `Dockerfile` installs the `Web-ISAPI-Ext` Windows feature, the 64-bit VC++ redistributable, and configures IIS to execute our ISAPI module.

## TODO
