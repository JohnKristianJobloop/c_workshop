namespace WordleDotNet.Services;

public static class WordListService
{
    public static async Task<string> FetchRandomWord(string fileName)
    {
        if (Path.Combine(AppContext.BaseDirectory, fileName) is not string filePath) throw new ArgumentException($"Error getting filepath with given fileName: {fileName}");

        if (await File.ReadAllLinesAsync(filePath) is not IEnumerable<string> lines) throw new ArgumentException($"Error getting data from file: {filePath}");

        return lines.OrderBy(line => Random.Shared.Next()).FirstOrDefault() ?? throw new ArgumentNullException("No valid line found in lines...");
    }
}