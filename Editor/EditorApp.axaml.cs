using System;
using System.Runtime.InteropServices;
using Avalonia;
using Avalonia.Controls.ApplicationLifetimes;
using Avalonia.Markup.Xaml;
using Toybox_Editor.Controls;
using Toybox_Editor.Views;
namespace Toybox_Editor;

public class EditorApp : Application
{
    public override void Initialize()
    {
        AvaloniaXamlLoader.Load(this);
    }

    public override void OnFrameworkInitializationCompleted()
    {
        if (ApplicationLifetime is IClassicDesktopStyleApplicationLifetime desktop)
        {
            var mainWindow = new MainWindow();
            mainWindow.ThreeDViewport.NativeWindowHost.NativeWindowHostControl = new NativeHostControl(LoadEngine());
            desktop.MainWindow = new MainWindow();
            
        }

        base.OnFrameworkInitializationCompleted();
    }
    
    // Loads engine and returns the 3d viewport window handle
    [DllImport("Engine.lib")]
    private static extern IntPtr LoadEngine();
}