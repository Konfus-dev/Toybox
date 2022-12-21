using System.Numerics;
using System.Runtime.InteropServices;

namespace Toybox_Editor.Data_Structs;

[StructLayout(LayoutKind.Sequential, Pack = 4)]
public struct Vertex
{
    public Vector3 Position;
    public Vector3 Normal;
}