using System.Runtime.InteropServices;

namespace EditorSharp.Interop;

public class EditorInterop
{
    [DllImport("../EditorCoreInterop/EditorCoreInterop.dll")]
    public static extern int LaunchViewport();
}