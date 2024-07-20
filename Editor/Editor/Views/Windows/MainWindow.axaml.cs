using Avalonia.Controls;
using Toybox.ViewModels;

namespace Toybox.Views.Windows;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        DataContext = new MainWindowVM();
        InitializeComponent();
    }
}