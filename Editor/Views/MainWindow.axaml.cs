using Avalonia.Controls;
using Toybox_Editor.ViewModels;

namespace Toybox_Editor.Views;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        DataContext = new MainWindowVM();
        InitializeComponent();
    }
}