using Avalonia.Controls;
using Avalonia.Platform;
using EditorSharp.Interop;

namespace EditorSharp.Views.Controls;

public partial class ThreeDViewport : UserControl
{
    public ThreeDViewport()
    {
        DataContext = this;
        InitializeComponent();
    }
}
    
public class Native3DViewport : NativeControlHost
{
    protected override IPlatformHandle CreateNativeControlCore(IPlatformHandle parent)
    {
        var editorCoreHandle = EditorCoreInterop.LaunchViewport();
        var platformHandle = new PlatformHandle(editorCoreHandle, Name);
        return platformHandle;
    }

    protected override void DestroyNativeControlCore(IPlatformHandle control)
    {
        // TODO: we have to tell the core to shutdown here
        base.DestroyNativeControlCore(control);
    }
}