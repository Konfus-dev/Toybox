using System.Threading.Tasks;
using Avalonia;
using Avalonia.Controls;
using Avalonia.Input;
using Avalonia.Media;
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
    public Native3DViewport()
    {
        DataContext = this;
    }
    
    protected override IPlatformHandle CreateNativeControlCore(IPlatformHandle parent)
    {
        var editorCoreHandle = EditorCoreInterop.LaunchViewport();
        var platformHandle = new PlatformHandle(editorCoreHandle, Name);
        EditorCoreInterop.UpdateViewport();
        return platformHandle;
    }

    protected override Size MeasureOverride(Size availableSize)
    {
        // TODO: need to get the viewport updating in a loop, rn only updates when resized...
        EditorCoreInterop.UpdateViewport();
        return base.MeasureOverride(availableSize);
    }

    protected override void DestroyNativeControlCore(IPlatformHandle control)
    {
        // TODO: we have to tell the core to shutdown here
        base.DestroyNativeControlCore(control);
    }
}