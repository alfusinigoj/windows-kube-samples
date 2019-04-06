# ASP with OLEDB

This project demonstrates a classic ASP application connecting to a SQL Server database via OLEDB.

## Dockerfile
Because the MDAC is generally available on Windows Server nothing special is required during the build of this docker image. This Dockerfile can be considered the bare minimum to run a classic ASP application on PKS with or without database access.

## TODO
* Config externalization
* K8s YAML spec

## Notes

This pattern in isolation is achievable on PASW today. PKS would only be required if additional concerns present themselves that are not achievable on PASW.