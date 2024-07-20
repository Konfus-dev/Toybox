using System.Runtime.InteropServices;
namespace Toybox.Core;

public class Interop
{
    [DllImport("../Interop/Interop.dll")]
    public static extern int LaunchViewport();
}