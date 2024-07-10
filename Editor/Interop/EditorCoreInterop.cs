using System.Runtime.InteropServices;

namespace EditorSharp.Interop;

public class EditorCoreInterop
{
    [DllImport("../EditorCoreInterop/EditorCoreInterop.dll")]
    public static extern int LaunchViewport();
    
    [DllImport("../EditorCoreInterop/EditorCoreInterop.dll")]
    public static extern void UpdateViewport();
}