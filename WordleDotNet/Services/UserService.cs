namespace WordleDotNet.Services;

public static class UserService
{
    public static string GetGuess()
    {
        string input;
        do
        {
            Console.WriteLine("Please guess a 5 letter word...");
            input = Console.ReadLine()!;
        } while (string.IsNullOrWhiteSpace(input) && input.Length != 5);
        return input;
    }
}