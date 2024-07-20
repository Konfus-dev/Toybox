using Avalonia.Controls;
using Avalonia.Platform;
namespace Toybox.Views.Controls;

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
    public Native3DViewport()
    {
        DataContext = this;
    }
    
    protected override IPlatformHandle CreateNativeControlCore(IPlatformHandle parent)
    {
        var editorCoreHandle = Core.Interop.LaunchViewport();
        var platformHandle = new PlatformHandle(editorCoreHandle, Name);
        return platformHandle;
    }

    protected override void DestroyNativeControlCore(IPlatformHandle control)
    {
        // TODO: we have to tell the core to shutdown here
        base.DestroyNativeControlCore(control);
    }
}