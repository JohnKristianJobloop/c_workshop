namespace WordleDotNet.Models;

public record Result(char C, ConsoleColor Color)
{
    public void Print()
    {
        Console.BackgroundColor = Color;
        Console.Write(C);
    }
};