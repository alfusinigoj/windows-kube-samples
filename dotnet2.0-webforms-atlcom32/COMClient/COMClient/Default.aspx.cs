using System;
using System.Collections.Generic;

using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace COMClient
{
    public partial class Default : System.Web.UI.Page
    {
        protected string Message { get; set; }
        protected void Page_Load(object sender, EventArgs e)
        {
            this.Message = new ATLPKSLib.Thing().Action();
        }
    }
}