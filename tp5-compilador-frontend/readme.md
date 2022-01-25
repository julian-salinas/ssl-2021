## Disposición de Directorios
```bash

├── analyzers  # Acá están los archivos de flex y bison  
├── docker  # Archivos de Docker, necesarios para compilar facilmente desde windows
├── txts  # Archivos de texto del enunciado
├── includes  # Headers (.h)
├── src  # Código (.c)
└── makefile  # Archivo para compilar el TP
```

## Ayuda: Compilar y Ejecutar el TP desde Windows vía Docker

#

### 1. Instalar [**Docker Desktop**](https://docs.docker.com/desktop/windows/install/) :whale:

### 2. En una terminal (puede ser la del `vscode`), dirigirse al directorio `tp5-compilador-frontend/`
```bash
vos@tupc: ~/<ruta-al-repositorio>
$ cd tp5-compilador-frontend
```
### 3. Ingresar en el directorio `docker`
```bash
$ cd docker
```

### 4. Iniciar el contenedor
```
$ docker-compose up
```

### Una vez la consola muestre lo siguiente
```bash
Creating network "docker_default" with the default driver
Creating tp5 ... done
Attaching to tp5
```

### Abrir una nueva terminal (sin cerrar la que está ejecutando el contenedor) (Botón `+` en la derecha de la terminal de `vscode`) y ejecutar el siguiente comando
```
$ docker exec -it tp5 /bin/sh
```

# Listo!
Ahora ya están dentro de una máquina con **Linux**, si utilizan `ls` pueden ver que están ubicados en el directorio del tp.
