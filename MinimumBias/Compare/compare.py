import re
import sys
sys.path.append('/home/lukas/root5.34/lib')
from ROOT import TCanvas, gRandom, TF1, TLegend,TFile
#import numpy as np

def compare(minb,zmumu):
	#########################################
	c = TCanvas("c","Comparison",200,10,700,500)
	
	minbNoV = minb.Get("Number of Vertices")
	zmumuNoV = zmumu.Get("Number of Vertices")
	
	minbNoV.GetXaxis().SetTitle("Number of Vertices")
	minbNoV.GetXaxis().SetRange(50,70)
	minbNoV.SetStats(0)
	
	minbNoV.Draw()
	minbNoV.SetLineColor(2)
	zmumuNoV.Draw("same")
	
	l = TLegend(0.69,0.51,0.88,0.87)
	l.AddEntry(minbNoV,"Minimum Bias","L")
	l.AddEntry(zmumuNoV,"Z Mu Mu","L")
	l.Draw()
	
	c.SaveAs(outfolder+"NumberofVertices.pdf")
	##########################################
	c2 = TCanvas("c","Comparison",200,10,700,500)
	
	minbAnV = minb.Get("Average Number of Interactions")
	zmumuAnV = zmumu.Get("Average Number of Interactions")
	
	minbAnV.GetXaxis().SetTitle("Average Number of Interactions")
	minbAnV.GetXaxis().SetRange(50,80)
	minbAnV.SetStats(0)
	
	minbAnV.Draw()
	minbAnV.SetLineColor(2)
	zmumuAnV.Draw("same")
	
	l2 = TLegend(0.69,0.51,0.88,0.87)
	l2.AddEntry(minbAnV,"Minimum Bias","L")
	l2.AddEntry(zmumuAnV,"Z Mu Mu","L")
	l2.Draw()
	
	c2.SaveAs(outfolder+"AverageNumberofInteractions.pdf")
	##########################################
	c3 = TCanvas("c","Comparison",200,10,700,500)
	
	minbspt = minb.Get("Sum of Track PT")
	zmumuspt = zmumu.Get("Sum of Track PT")
	
	minbspt.GetXaxis().SetTitle("Sum of Track PT")
	#minbspt.GetXaxis().SetRange(50,80)
	minbspt.SetStats(0)
	
	minbspt.Draw()
	minbspt.SetLineColor(2)
	zmumuspt.Draw("same")
	
	l3 = TLegend(0.69,0.51,0.88,0.87)
	l3.AddEntry(minbspt,"Minimum Bias","L")
	l3.AddEntry(zmumuspt,"Z Mu Mu","L")
	l3.Draw()
	
	c3.SaveAs(outfolder+"Sum of Track PT.pdf")
	##########################################
	c4 = TCanvas("c","Comparison",200,10,700,500)
	
	minbprimpt = minb.Get("Sum of Primary Track PT")
	zmumuprimpt = zmumu.Get("Sum of Primary Track PT")
	
	minbprimpt.GetXaxis().SetTitle("Sum of Primary Track PT")
	#minbspt.GetXaxis().SetRange(50,80)
	minbprimpt.SetStats(0)
	
	minbprimpt.Draw()
	minbprimpt.SetLineColor(2)
	zmumuprimpt.Draw("same")
	
	l4 = TLegend(0.69,0.51,0.88,0.87)
	l4.AddEntry(minbprimpt,"Minimum Bias","L")
	l4.AddEntry(zmumuprimpt,"Z Mu Mu","L")
	l4.Draw()
	
	c4.SaveAs(outfolder+"Sum of Primary Track PT.pdf")
	##########################################
	c5 = TCanvas("c","Comparison",200,10,700,500)
	
	minbpilept = minb.Get("Sum of Pile Up Track PT")
	zmumupilept = zmumu.Get("Sum of Pile Up Track PT")
	
	minbpilept.GetXaxis().SetTitle("Sum of Pile Up Track PT")
	#minbspt.GetXaxis().SetRange(50,80)
	minbpilept.SetStats(0)
	
	minbpilept.Draw()
	minbpilept.SetLineColor(2)
	zmumupilept.Draw("same")
	
	l5 = TLegend(0.69,0.51,0.88,0.87)
	l5.AddEntry(minbpilept,"Minimum Bias","L")
	l5.AddEntry(zmumupilept,"Z Mu Mu","L")
	l5.Draw()
	
	c5.SaveAs(outfolder+"Sum of Pile Up Track PT.pdf")
	
	

	
	return 0

compfolder = "/home/lukas/Bachelorarbeit/HadRec/MinimumBias/tryout/"
minbiasfile = "MCminbiastry.root"
zmumufile = "MCzmumutry.root"
outfolder = "/home/lukas/Bachelorarbeit/HadRec/MinimumBias/Compare/output/"
configfile = "config.txt"

minb = TFile(compfolder+minbiasfile)
zmumu = TFile(compfolder+zmumufile)

compare(minb,zmumu)
