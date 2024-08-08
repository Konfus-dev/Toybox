using Avalonia.Controls;
using Avalonia.Platform;
using System;
using System.Threading.Tasks;
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
    private bool _viewportAppLaunched;
    private Task? _viewportRenderTask;

    public Native3DViewport()
    {
        DataContext = this;
    }

    protected override IPlatformHandle CreateNativeControlCore(IPlatformHandle parent)
    {
        var editorCoreHandle = Launch();
        var platformHandle = new PlatformHandle(editorCoreHandle, Name);
        return platformHandle;
    }

    protected override void DestroyNativeControlCore(IPlatformHandle control)
    {
        // TODO: we have to tell the core to shutdown here
        _viewportRenderTask?.Dispose();
        base.DestroyNativeControlCore(control);
    }

    private Int32 Launch()
    {
        Int32 editorCoreHandle = 0;

        void UpdateLoop()
        {
            if (!_viewportAppLaunched)
            {
                editorCoreHandle = Core.Interop.LaunchViewport();
                _viewportAppLaunched = true;
            }

            while (true)
            {
                Core.Interop.UpdateViewport();
            }
        }

        _viewportRenderTask = Task.Factory.StartNew(
            action: UpdateLoop, 
            creationOptions: TaskCreationOptions.LongRunning);

        while (!_viewportAppLaunched)
        {
            // do nothing... waiting for the viewport to launch
        }

        return editorCoreHandle;
    }
}