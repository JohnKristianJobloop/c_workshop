using System.Diagnostics.Contracts;
using WordleDotNet.Models;

namespace WordleDotNet.Services;

public static class WordleService
{
    public static IEnumerable<Result> CompareWords(string guess, string word)
    {
        if (guess.Length != word.Length && guess.Length != 5) throw new ArgumentException($"Invalid Length of {guess}");

        var charCountInWord = word.GroupBy(c => c).ToDictionary(g => g.Key, g => g.Count());;

        return guess.Select((c, i) =>
        {
            if (c == word[i]) return new Result(c, ConsoleColor.Green);
            else if(charCountInWord.Any(g => g.Key == c && g.Value > 0))
            {
                charCountInWord[c]--;
                return new Result(c, ConsoleColor.Yellow);
            }
            else return new Result(c, ConsoleColor.Red);
        });
    }
    public static void PrintResult(IEnumerable<Result> results) => results.ToList().ForEach(res => res.Print());
    public static bool CheckForWin(IEnumerable<Result> results) => results.All(res => res.Color == ConsoleColor.Green);
}