/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:38:36 by paescano          #+#    #+#             */
/*   Updated: 2023/12/15 17:27:38 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
	if (this != &src)
	{
		setSigned(src.getSigned());
		this->_target = src.getTarget();
	}
	return *this;
}

std::string		ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void			ShrubberyCreationForm::executeAction() const {
	std::ofstream outFile(this->_target + "_shrubbery");
    if (!outFile) 
	{
        std::cerr << "can't open/create" << this->_target + "_shrubbery" << std::endl;
        return ;
    }
    outFile << 
    "         ; ; ;\n"
    "       ;        ;  ;     ;;    ;\n"
    "    ;                 ;         ;  ;\n"
    "                    ;\n"
    "                   ;                ;;\n"
    "   ;          ;            ;              ;\n"
    "   ;            ';,        ;               ;\n"
    "   ;              'b      *\n"
    "    ;              '$    ;;                ;;\n"
    "   ;    ;           $:   ;:               ;\n"
    " ;;      ;  ;;      *;  @):        ;   ; ;\n"
    "              ;     :@,@):   ,;**:'   ;\n"
    "  ;      ;,         :@@*: ;;**'      ;   ;\n"
    "           ';o;    ;:(@';@:;  ;\n"
    "   ;  ;       ;bq,;;:,@@*;   ,*      ;  ;\n"
    "              ,p$q8,:@);  ;p*;      ;\n"
    "       ;     ;  ; ;@@Pp@@*:    ;  ;\n"
    "        ;  ; ;;    Y7:.:     ;  ;\n"
    "                  :@):.\n"
    "                 .:@::.\n"
    "               .::(@:."
    << std::endl;
}

AForm *			ShrubberyCreationForm::clone(std::string target) {
    return new ShrubberyCreationForm(target);
}
