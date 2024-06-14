using Avalonia.Controls;
using EditorSharp.ViewModels;

namespace EditorSharp.Views.Windows;

public partial class MainWindow : Window
{
    public MainWindow()
    {
        DataContext = new MainWindowVM();
        InitializeComponent();
    }
}