#include "output.h"

void output::Execute()
{
	OutputContext* out_cxt = new OutputContext();
	OutputStrategy* out = out_cxt->getOutputFormat(this->arg_format);
	if (out)out->Output();
	else std::cout << "Output failed! Please check if the .csv file exist or command is right!\n";
}
