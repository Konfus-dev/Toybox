using Avalonia.Controls;
namespace Toybox_Editor.Controls;

public partial class GameView : UserControl
{
    public GameView()
    {
        DataContext = this;
        InitializeComponent();
    }
}