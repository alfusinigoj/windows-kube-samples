using System;
using System.Collections.Generic;

using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Configuration;

namespace WebConfigConfigMap
{
    public partial class Default : System.Web.UI.Page
    {
        protected string ConfigPulledFrom { get; set; }
        protected void Page_Load(object sender, EventArgs e)
        {
            this.ConfigPulledFrom = ConfigurationManager.AppSettings["ConfigPulledFrom"];
        }
    }
}