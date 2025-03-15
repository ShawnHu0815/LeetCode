using System;
    using System.Collections.Generic;
    using LeetCode.Properties;
    
    namespace LeetCode
    {
        public class W152Q3 : ILeetCodeQuestion
        {
            public class Spreadsheet
            {
                private int rows;
                private int[,] grid;

                private List<int[]> sheet = new List<int[]>();
                
                public Spreadsheet(int rows)
                {
                    for (int i = 0; i < rows; i++)
                    {
                        sheet.Add(new int[26]);
                    }
                }
                
                public void SetCell(string cell, int value)
                {
                    int row, col;
                    (row, col) = ParseCellReference(cell);
                    sheet[row][col] = value;
                }
                
                public void ResetCell(string cell)
                {
                    int row, col;
                    (row, col) = ParseCellReference(cell);
                    sheet[row][col] = 0;
                }
                
                public int GetValue(string formula)
                {
                    int op1 = 0, op2 = 0;
                    string[] parts = formula.Split('+');
                    string part1 = parts[0].Trim('=');
                    if (char.IsLetter(part1[0]))
                    {
                        int row, col;
                        (row, col) = ParseCellReference(part1);
                        op1 = sheet[row][col];
                    }
                    else
                    {
                        op1 = int.Parse(part1);
                    }
                    string part2 = parts[1];
                    if (char.IsLetter(part2[0]))
                    {
                        int row, col;
                        (row, col) = ParseCellReference(part2);
                        op2 = sheet[row][col];
                    }
                    else
                    {
                        op2 = int.Parse(part2);
                    }
                    return op1 + op2;
                }
                
                // Helper method to parse cell reference
                private (int row, int col) ParseCellReference(string cellRef)
                {
                    int col = cellRef[0] - 'A';
                    int row = int.Parse(cellRef.Substring(1));
                    return (row, col);
                }
            }
    
            public void Run()
            {
                Console.WriteLine("运行 W152Q3: 电子表格");
                
                // Test case from problem description
                Spreadsheet spreadsheet = new Spreadsheet(3);
                
                Console.WriteLine($"getValue(\"=5+7\"): {spreadsheet.GetValue("=5+7")}");
                
                spreadsheet.SetCell("A1", 10);
                Console.WriteLine($"getValue(\"=A1+6\"): {spreadsheet.GetValue("=A1+6")}");
                
                spreadsheet.SetCell("B2", 15);
                Console.WriteLine($"getValue(\"=A1+B2\"): {spreadsheet.GetValue("=A1+B2")}");
                
                spreadsheet.ResetCell("A1");
                Console.WriteLine($"getValue(\"=A1+B2\"): {spreadsheet.GetValue("=A1+B2")}");
                
                // You can add additional test cases here
            }
        }
    }