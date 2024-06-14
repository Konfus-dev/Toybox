using Avalonia.Controls;
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
    protected override IPlatformHandle CreateNativeControlCore(IPlatformHandle parent)
    {
        // TODO: this is freezing for some reason... figure out why!
        // AppendRuntimeIdentifierToOutputPath and AppendTargetFrameworkToOutputPath both changed to false, this the reason? Change back and test!
        var editorCoreHandle = EditorCoreInterop.LaunchViewport();
        var platformHandle = new PlatformHandle(editorCoreHandle, Name);
        return platformHandle;
    }

    public override void Render(DrawingContext context)
    {
        EditorCoreInterop.UpdateViewport();
        base.Render(context);
    }

    protected override void DestroyNativeControlCore(IPlatformHandle control)
    {
        // TODO: we have to tell the core to shutdown here
        base.DestroyNativeControlCore(control);
    }
}