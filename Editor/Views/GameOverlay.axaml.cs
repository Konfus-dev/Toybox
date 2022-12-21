using Avalonia.Controls;
using Avalonia.Markup.Xaml;
using Toybox_Editor.ViewModels;
namespace Toybox_Editor.Views;

public partial class GameOverlay : UserControl
{
    public GameOverlay()
    {
        DataContext = new GameOverlayVM();
        InitializeComponent();
    }

    private void InitializeComponent()
    {
        AvaloniaXamlLoader.Load(this);
    }
}