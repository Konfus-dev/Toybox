using System;
using Avalonia.Controls;
using Avalonia.Platform;

namespace EditorSharp.Views.Controls;

public partial class NativeWindowHost : UserControl
{
    public NativeWindowHost()
    {
        DataContext = this;
        InitializeComponent();
    }
}

public class NativeHostControl : NativeControlHost
{
    private IntPtr? _handle;

    public NativeHostControl(IntPtr? handle = null)
    {
        _handle = handle;
    }

    public NativeHostControl()
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
        _handle = null;
        base.DestroyNativeControlCore(control);
    }
}