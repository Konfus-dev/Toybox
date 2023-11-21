using Avalonia.Controls;
namespace Toybox_Editor.Controls;

public partial class ThreeDViewport : UserControl
{
    public ThreeDViewport()
    {
        DataContext = this;
        InitializeComponent();
    }
}