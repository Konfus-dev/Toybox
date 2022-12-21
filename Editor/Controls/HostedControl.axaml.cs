using System;
using Avalonia.Controls;
using Avalonia.Platform;
namespace Toybox_Editor.Controls;

public partial class HostedControl : UserControl
{
    public HostedControl()
    {
        DataContext = this;
        InitializeComponent();
    }
}

public class HostedNativeControl : NativeControlHost
{
    private IntPtr? _handle;

    public HostedNativeControl(IntPtr? handle = null)
    {
        _handle = handle;
    }

    public HostedNativeControl()
    {
        _handle = null;
    }

    protected override IPlatformHandle CreateNativeControlCore(IPlatformHandle parent)
    {
        IPlatformHandle platformHandle;
        if (_handle == null)
        {
            platformHandle = base.CreateNativeControlCore(parent);
            _handle = platformHandle.Handle;
        }
        else
        {
            platformHandle = new PlatformHandle((IntPtr) _handle, Name);
        }
                
        return platformHandle;
    }

    protected override void DestroyNativeControlCore(IPlatformHandle control)
    {
        //_handle = null;
        base.DestroyNativeControlCore(control);
    }
}