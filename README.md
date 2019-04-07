# PKSW Samples

Here are sample projects for a number of common scenarios where a Solutions Architect might target PKS Windows. Most of these scenarios represent legacy applications, but a few may represent patterns for modern microservices architectures.

In general the individual projects are meant to be small and only demonstrate the resolution to a single problem, but more complete demonstrations may be added later.

Unless noted otherwise the strategy used in these samples is to have zero code change in the target projects. It's meant to simulate just dropping the Dockerfile and K8s artifacts above the solution directory with no polution of the app source tree itself. That may or may not be the most appropriate strategy in the field and I'm not advocating that as a best practice. Any samples that do attempt to illustrate best practices (thus likely requiring code/project modification) will be notated accordingly.

*These Dockerfiles should be buildable and runnable on Windows 10, but in order to deploy them to PKS they must be built on Server 2019.*

## Projects

* **asp-with-oledb** A classic ASP project that connects to a SQL Server database via OLEDB

* **asp-with-odbc** A classic ASP project that connects to a SQL Server database via ODBC with a DSN configured at the system level

* **dotnet2.0-webforms** An ASP.NET 2.0 WebForms sample

* **dotnet2.0-webconfig-configmap** An ASP.NET 2.0 WebForms sample whose configuration is sourced from a ConfigMap

* **dotnet2.0-webconfig-atlcom32** An ASP.NET 2.0 WebForms sample that depends on a custom 32-bit ATL/COM library

* **dotnet4x-selfhostedwcf** A WCF service hosted in a Windows service