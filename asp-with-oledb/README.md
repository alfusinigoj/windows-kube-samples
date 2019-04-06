# ASP with OLEDB

This project demonstrates a classic ASP application connecting to a SQL Server database via OLEDB.

## Dockerfile
Because the MDAC is generally available on Windows Server nothing special is required during the build of this docker image. This Dockerfile can be considered the bare minimum to run a classic ASP application on PKS with or without database access.

The Dockerfile assumes that you have the contents of your web application in the `wwwroot` directory at the same level as the Dockerfile.

## wwwroot/default.asp 
In `default.asp` you'll have to specify the connection string relevant to your environment. 

While specifying such information directly in code is not desirable, it's a pattern often found in legacy ASP applications. In the future content will be added demonstrating config externalization.

## TODO
* Config externalization (Maybe separate sample)

## Notes

This pattern in isolation is achievable on PASW today. PKS would only be required if additional concerns present themselves that are not achievable on PASW.