using System;
using Avalonia.Controls;
using Avalonia.Controls.Templates;
using Toybox_Editor.ViewModels;
namespace Toybox_Editor;

public class ViewLocator : IDataTemplate
{
    public IControl Build(object data)
    {
        var name = data.GetType().FullName!.Replace("VM", "");
        var type = Type.GetType(name);

        if (type != null)
        {
            return (Control) Activator.CreateInstance(type)!;
        }

        return new TextBlock {Text = "Not Found: " + name};
    }

    public bool Match(object data)
    {
        return data is ViewModel;
    }
}