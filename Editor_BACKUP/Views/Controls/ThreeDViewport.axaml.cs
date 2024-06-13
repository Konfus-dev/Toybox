using Avalonia.Controls;

namespace EditorSharp.Views.Controls;

public partial class ThreeDViewport : UserControl
{
    public ThreeDViewport()
    {
        DataContext = this;
        InitializeComponent();
    }
}