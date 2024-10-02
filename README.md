# 42Porto_Push_swap
**Push_Swap** is a C project from the 42 Porto Common Core program. The main goal of this project is to organize a list of random numbers in ascending order. To achieve this, only the use of two stacks (referred to as **stack_a** and **stack_b**) and some predefined movements of elements within and between the stacks are allowed.
For more detailed information, look at the [**subject of this project**](https://github.com/Uatilla/42Porto_Push_swap/blob/main/Push_swap_en.subject.pdf).

[![MasterHead](https://github.com/Uatilla/42Porto_Push_swap/assets/112968804/16dc6c25-39f5-40d6-bf70-ee264a05893a)](https://www.linkedin.com/in/uatilla/)


## Getting Started

You just need to download or clone this git repository.
`git clone git@github.com:Uatilla/42Porto_Push_swap.git`

## How to use it

* Run `make` to build all necessary files.
* Then run `./push_swap <*Elements*>`, you should replace *Elements* by any amount of integer negative or positive numbers, since they don’t repeat in the list, for example:
* `./push_swap 5 3 -8 1 0 7`.
* To delete all .o files: `make clean`.
* To delete all .o files and library: `make fclean`.
* To delete all .o files, library, and rebuild the Mandatory .o files: `make re`.


## Rules

**List of Movements**

Below there is the list of movements allowed:

![image](https://github.com/Uatilla/42Porto_Push_swap/assets/112968804/159c5438-0494-486e-8583-a360f7eaf2fd)


**Grades**

The evaluation grades are based on the number of movements needed to order the list:

![image](https://github.com/Uatilla/42Porto_Push_swap/assets/112968804/86e9fb58-2fe3-4b74-9b87-d7415c44b49b)

**Norminette:**

The Norminette is a tool provided by 42 Network to check whether the source code complies with the school's norm. The rules include the prohibition of ‘for’ loops, a limit of 25 lines, and no more than 4 parameters in each function, among other specifications.

Here is a [link](https://github.com/gdamion/Norminette/blob/master/norme.en.pdf) to more details about what is evaluated by the Norminette tool.

## How my project works

![Algorithm flowchart example](https://github.com/Uatilla/42Porto_Push_swap/assets/112968804/3a5fa5bb-1acf-4b58-a729-43c95cb1bc4f)


To set up the structure, various methods can be applied, such as using an array of integers or a singly linked list. For this project, I chose a **double-linked list**, as it offers the most efficient way to move values around, minimizing movements. Once the head and the tail of the list are connected, it becomes possible to 'jump' between the start and end of the list easily.

To sort the data, numerous methods can be applied, such as Radix, Insert Sort, and others. I opted for the **Turkish Method** due to its high efficiency, typically requiring fewer movements compared to alternative methods.

## Results

The program reached the grade **100** needing **4,861 moves** to sort 500 numbers (the minimum to reach grade 100 are 5,500), so **12%** more efficient.

## Sources

* **Double Linked List: Neso Academy** has one of the best YouTube channels that explains C programming concepts very easily and clear, here is the [link](https://www.youtube.com/watch?v=e9NG_a6Z0mg&pp=ygUSZG91YmxlIGxpbmtlZCBsaXN0).

* **Turkish Method:** Many thanks to **A. Yigit Ogun** who explained about the method, you can reach his content [here](https://medium.com/@ayogun/push-swap-c1f5d2d41e97). 

* **Push Swap Overview** from Jamie Dawson [link](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a).

## Contributing

Contributions to the project are welcome! If you have any ideas, improvements, or bug fixes, please submit them as issues or pull requests to this repository.

<div align="center">
  <h1><b>Welcome to my new brave world!</b></h1> 
  <h2><b>00100010 01000010 01100101 00100000 01110111 01100001 01110100 01100101 01110010 00100000 01101101 01111001 00100000 01100110 01110010 01101001 01100101 01101110 01100100 00100010 00100000 01000010 01110010 01110101 01100011 01100101 00100000 01001100 01100101 01100101</b></h2>
</div>

<!---
SMALL ICONS
--->
<div style="text-align: center;">
  <a href='https://www.linkedin.com/in/uatilla' target="_blank" style="display: inline-block; margin: 0 10px;">
    <img alt='Linkedin' src='https://img.shields.io/badge/LinkedIn-100000?style=flat&logo=Linkedin&logoColor=white&labelColor=0A66C2&color=0A66C2'/>
  </a>
  <a href='https://profile.intra.42.fr/users/uviana-a' target="_blank" style="display: inline-block; margin: 0 10px;">
    <img alt='42' src='https://img.shields.io/badge/Porto-100000?style=flat&logo=42&logoColor=white&labelColor=000000&color=000000'/>
  </a>
  <img src="https://komarev.com/ghpvc/?username=uatilla&label=Profile%20views&color=0e75b6&style=flat" alt="uatilla" style="display: inline-block; margin: 0 10px;" />
</div>


## About me

- 👋 I'm `Uatilla Viana Almeida`.
- 🌱 I'm currently studying Common Core at [**42 Porto**](https://www.42porto.com) after successfully completing the Piscine.
- 👀 I'm interested in `Bitcoin`, `Games` and `Sports` of all kinds.
- 🚀 Additionally, I have an interest in `AI`, `Python`, `Data Analysis` and `Project Management`.
- 📫 You can reach me on [**LinkedIn**](https://www.linkedin.com/in/uatilla/).
- 🤔 Feeling amazing about how AI can help our society.

<div align="center">

## Skills
<p align="left">
  <a href="https://skillicons.dev">
    <img src="https://skillicons.dev/icons?i=c,python,git,github,bash,linux,vim,vscode,sketchup,sql" />
  </a>
</p>

<p><img align="left" src="https://github-readme-stats.vercel.app/api/top-langs?username=uatilla&show_icons=true&locale=en&layout=compact" alt="uatilla" /></p>

<p>&nbsp;<img align="left" src="https://github-readme-stats.vercel.app/api?username=uatilla&show_icons=true&locale=en" alt="uatilla" /></p>

<p><img align="left" src="https://github-readme-streak-stats.herokuapp.com/?user=uatilla&" alt="uatilla" /></p>
