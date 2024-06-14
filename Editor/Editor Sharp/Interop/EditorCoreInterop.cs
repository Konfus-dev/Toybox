using System.Runtime.InteropServices;

namespace EditorSharp.Interop;

public class EditorCoreInterop
{
    [DllImport("../EditorCore/EditorCore.dll")]
    public static extern int LaunchViewport();
    
    
    [DllImport("../EditorCore/EditorCore.dll")]
    public static extern int UpdateViewport();
}