using Avalonia.Controls;
using Toybox.ViewModels;

namespace Toybox.Views;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        DataContext = new MainWindowVM();
        InitializeComponent();
    }
}