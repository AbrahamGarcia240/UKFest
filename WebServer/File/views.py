from django.shortcuts import render
import File.forms as f
import File.models as m
from File.Sender import Sender
def index(request):
    msg1 = "Selecciona un Archivo"
    init = f.GetFile()
    variables = {"form":init,"msg":msg1}
    if request.method == 'POST':
        form = f.GetFile(request.POST, request.FILES)
        n = request.POST.get("n"),
        q = request.FILES['file_to_send']
        m.Archivo(n = n,file_to_send = q).save()
        sender = Sender(q.name)
        sender.sendN(n[0])
        #sender.sendFile()
        return render(request,'index.html',variables)

    return render(request,'index.html',variables)
