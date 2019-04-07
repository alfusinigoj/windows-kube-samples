# WCF Hosted in a Windows Service

Here is a Windows Service hosting a WCF Service. You could argue this is more of a Windows Service example than a WCF example, but it still demonstrates a common pattern for operationalizing WCF.

Note that in the pure case of WCF refactoring the Service as an .EXE and running it on PAS likely makes more sense.

## Dockerfile

Creates a user for the Windows Service to run under and installs the Service with `installutil.exe`.