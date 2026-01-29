using System.Diagnostics;
using WordleDotNet.Services;

Console.WriteLine("Welcome to WordleDotNet....!");

long cpu_us =
    (long)(Process.GetCurrentProcess()
        .TotalProcessorTime.TotalMilliseconds * 1000);
var word = await WordListService.FetchRandomWord("wl.txt");
cpu_us =
    (long)(Process.GetCurrentProcess()
        .TotalProcessorTime.TotalMilliseconds * 1000) - cpu_us;
Console.WriteLine($"elapsed: {cpu_us}");
int tries = 0;
do
{
    var guess = UserService.GetGuess();
    var results = WordleService.CompareWords(guess, word);
    WordleService.PrintResult(results);
    Console.WriteLine();
    Console.ResetColor();
    if (!WordleService.CheckForWin(results))
    {
        tries++;
        continue;
    }
    else
    {
        Console.WriteLine("You Win!");
        break;
    }
} while (tries < 6);