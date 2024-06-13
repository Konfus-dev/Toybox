using System.Runtime.InteropServices;

namespace EditorSharp.Interop;

public class EditorCoreInterop
{
    [DllImport("EditorCore.dll")]
    public static extern int LaunchViewport();
}