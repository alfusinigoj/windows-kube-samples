# PKSW Samples

Here are sample projects for a number of common scenarios where a Solutions Architect might target PKS Windows. Some of these scenarios represent legacy applications, but others represent patterns for modern microservices architectures.

In general the individual projects are meant to be small and only demonstrate the resolution to a single problem, but more complete demonstrations may be added later.

These Dockerfiles should be buildable and runnable on Windows 10, but in order to deploy them to PKS they must be build on Server 2019.

Unless noted otherwise the strategy used in these samples is to have zero code change in the target projects. That may or may not be the most appropriate strategy in the field. Any samples that illustrate best practices requiring code/project modification will be notated accordingly.

## Projects

* **asp-with-oledb** A classic ASP project that connects to a SQL Server database via OLEDB

* **asp-with-odbc** A classic ASP project that connects to a SQL Server database via ODBC with a DSN configured at the system level

* **dotnet2.0-webforms** An ASP.NET 2.0 WebForms sample
