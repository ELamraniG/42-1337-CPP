#include "Form.hpp"


Form::Form() : grade_to_excute(12) , grade_to_sign(20) , name("useless"), is_signed(false) 
{

}
Form::~Form() 
{

}
Form::Form(std::string name, int grade_to_excute, int grade_to_sign, bool is_signed) : name(name), grade_to_excute(grade_to_excute), grade_to_sign(grade_to_sign), is_signed(is_signed) 
{

}
Form::Form(const Form &cpy) : is_signed(is_signed), grade_to_excute(grade_to_excute), grade_to_sign(grade_to_sign), name(name)
{
    *this = cpy;
}
Form & Form::operator=(const Form &cpy)
{
    this->is_signed = cpy.is_signed;        
}



    const std::string Form::get_name()
    {
        return this->name;
    }
    bool Form::get_is_signed()
    {
        return this->is_signed;
    }
    const int Form::get_grade_to_sign()
    {
        return grade_to_sign;
    }
    const int Form::get_grade_to_excute()
    {
        return grade_to_excute;
    }
    
void Form::beSigned(Bureaucrat &buro)
{
    
}

// later add << and gradetoo..