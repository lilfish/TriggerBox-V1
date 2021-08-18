using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TriggerBoxApplication
{
    public class ToolsClass
    {
        public double start;

        public void setStart(DateTime time)
        {
            this.start = time.Millisecond;
            this.start += TimeSpan.FromSeconds(time.Second).TotalMilliseconds;
            this.start += TimeSpan.FromMinutes(time.Minute).TotalMilliseconds;
            this.start += TimeSpan.FromHours(time.Hour).TotalMilliseconds;
        }
        public double getStart()
        {
            return this.start;
        }
    }
}
