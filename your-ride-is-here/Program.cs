using System;

namespace RideIsHere
{
    class Program
    {
        static double cometTotal = 1;
        private static double groupTotal = 1;

        static void Main(string[] args)
        {
            Console.WriteLine("Enter a comet name: ");
            string cometName = Console.ReadLine();
            cometName = cometName.ToUpper();
            Console.WriteLine("Now enter a group name: ");
            string groupName = Console.ReadLine();
            groupName = groupName.ToUpper();
            Console.WriteLine(cometName + " " + groupName);
            
            CometProductOfLetters(cometName);
            GroupProductOfLetters(groupName);
            StayOrGo();
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
            Console.WriteLine(cometTotal % 47);
            Console.WriteLine(groupTotal % 47);
            
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