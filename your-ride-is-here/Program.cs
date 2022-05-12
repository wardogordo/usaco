using System;
using System.Net;
using System.Text.RegularExpressions;

namespace RideIsHere
{
    class Program
    {
        static double cometTotal = 1;
        private static double groupTotal = 1;
        private static string cometName;
        private static string groupName;
        private static bool cometNameValidated;

        static void Main(string[] args)
        {
            EnterCometName();
            cometName = cometName.ToUpper();
            cometNameValidated = true;
            EnterGroupName();
            groupName = groupName.ToUpper();
            Console.WriteLine("Your input: " + cometName + " " + groupName);
            CometProductOfLetters(cometName);
            GroupProductOfLetters(groupName);
            StayOrGo();
        }

        static void EnterCometName()
        {
            Console.WriteLine("Enter a comet name: ");
            cometName = Console.ReadLine();
            ValidateInput(cometName);
        }
        
        static void EnterGroupName()
        {
            Console.WriteLine("Now enter a group name: ");
            groupName = Console.ReadLine();
            ValidateInput(groupName);
        }
         static void ValidateInput(string str)
        {
            if (!Regex.IsMatch(str, @"^[a-zA-Z]+$"))
            {
                Console.WriteLine("Please only use standard alphabet characters.");
                Console.WriteLine ("Your entry: " + str);
                if (cometNameValidated)
                {
                    EnterGroupName();
                }
                else
                {
                    EnterCometName();
                }
                
            }

            if (str.Length != 6)
            {
                Console.WriteLine("Please enter a 6 character name.");
                Console.WriteLine ("Your " + str.Length + " character entry: " + str);
                if (cometNameValidated)
                {
                    EnterGroupName();
                }
                else
                {
                    EnterCometName();
                }
            }
        }
        static void CometProductOfLetters(string str)
        {
            foreach (var letter in str)
            {
                var letterValue = (int) letter;
                cometTotal *= letterValue - 64;
            }
            
            Console.WriteLine("Comet total: " + cometTotal);
        }
        
        static void GroupProductOfLetters(string str)
        {
            foreach (var letter in str)
            {
                var letterValue = (int) letter;
                groupTotal *= letterValue - 64;
            }
            
            Console.WriteLine("Group total: " + groupTotal);
        }

        static void StayOrGo()
        {
            Console.WriteLine("\tComet Total % 47: " + cometTotal % 47);
            Console.WriteLine("\tGroup Total % 47: " + groupTotal % 47);
            
            if (cometTotal % 47 == groupTotal % 47)
            {
                Console.WriteLine("GO");
            }
            else
            {
                Console.WriteLine("STAY");
            }
        }
    }
}