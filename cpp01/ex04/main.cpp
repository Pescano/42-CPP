/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:39:48 by paescano          #+#    #+#             */
/*   Updated: 2023/11/29 19:26:05 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	checkerArgs(int argc, char **argv)
{
	if(argc != 4){
		std::cout << "Error: Wrong arguments" << std::endl;
		std::cout << "Usage: " << argv[0] << " <filename> <str1> <str2>" << std::endl;
		return 1;
	}
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	if(s1 == "" || s2 == ""){
		std::cout << "Error: Strings can't be empty" << std::endl;
		return 1;
	}
	return 0;
}

void	replaceStr(std::string filename, std::string s1, std::string s2)
{
	std::ifstream ifs;
	std::string output;
	std::string input;
	std::string line;
	std::string result;
	size_t	pos;

	ifs.open(filename);
	if(ifs.is_open()){
		while (ifs.good())
		{
			std::getline(ifs, input);
			output.append(input);
			if (ifs.peek() != EOF)
				output.append("\n");	
		}
		ifs.close();
	}
	else{
		std::cout << "Can't open the file" << std::endl;
		return;
	}
	std::ofstream ofs(filename + ".replace");
	if(!ofs.is_open()){
		std::cout << "Can't open the file" << std::endl;
		return;
	}
	pos = output.find(s1);
	while(pos != std::string::npos){
		output.erase(pos, s1.length());
		output.insert(pos, s2);
		pos = output.find(s1);
	}
	ofs << output;
	ofs.close();
}

int main(int argc, char **argv){
	if(checkerArgs(argc, argv) == 1)
		return 1;
	replaceStr(argv[1], argv[2], argv[3]);
	return 0;
}
