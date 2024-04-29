# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D, art3d
from matplotlib.animation import FuncAnimation
from matplotlib.animation import PillowWriter
from matplotlib.colors import Normalize
from matplotlib.cm import viridis

# Fonction pour créer un cylindre
def create_cylinder(center_x, center_y, radius, height, color):
    z = np.linspace(-height / 2, height / 2, 100)
    theta = np.linspace(0, 2 * np.pi, 100)
    theta_grid, z_grid = np.meshgrid(theta, z)
    x_grid = radius * np.cos(theta_grid) + center_x
    y_grid = radius * np.sin(theta_grid) + center_y
    return x_grid, y_grid, z_grid

# Lecture du fichier de configuration
config = {}
with open('../config.txt', 'r') as file:
    for line in file:
        line = line.strip()
        if line.startswith('//') or not line:
            continue
        key, value = line.split('=')
        config[key] = float(value)

rayon = config['tele_rayon']
hauteur = config['tele_hauteur']

skip=10
# Chargement des données des muons
data = np.loadtxt('../../data/muon')
time = data[11000:22000:skip, 0]
x = data[11000:22000:skip, 1]
y = data[11000:22000:skip, 2]
z = data[11000:22000:skip, 3]

# Chargement des données des photons
photon_data = np.loadtxt('../../data/photonstxt')
photon_time = photon_data[:, 0]
photon_x = photon_data[:, 1]
photon_y = photon_data[:, 2]
photon_z = photon_data[:, 3]

# Création d'un objet de normalisation et d'une colormap
norm = Normalize(vmin=np.min(photon_time), vmax=np.max(photon_time))

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')


# Définir les limites pour une visualisation claire
ax.set_xlim([-2*rayon-10, 2*rayon+10])
ax.set_ylim([-2*rayon-10, 2*rayon+10])
ax.set_zlim([-hauteur/2-10, hauteur/2+10])

# Ajouter un cylindre au plot
cx, cy, cz = create_cylinder(0, 0, rayon, hauteur, 'yellow')
ax.plot_surface(cx, cy, cz, color='yellow', alpha=0.25)

line, = ax.plot([], [], [], 'r-', color='#ADD8E6', label='Trajectory', linewidth=2)
point, = ax.plot([], [], [], 'o', color='blue', markersize=6)

# Créer un scatter plot vide pour les points photons
photon_points = ax.scatter([], [], [], color='red', s=100)

time_text = ax.text2D(0.05, 0.95, '', transform=ax.transAxes, fontsize='large')
photon_count_text = ax.text2D(0.05, 0.90, '', transform=ax.transAxes, fontsize='large')

def init():
    line.set_data([], [])
    line.set_3d_properties([])
    point.set_data([], [])
    point.set_3d_properties([])
    photon_points._offsets3d = ([], [], [])
    time_text.set_text('')
    photon_count_text.set_text('')
    return line, point, photon_points, time_text, photon_count_text

def update(frame):
    line.set_data(x[:frame], y[:frame])
    line.set_3d_properties(z[:frame])
    point.set_data(x[frame], y[frame])
    point.set_3d_properties(z[frame])
    mask = photon_time <= time[frame]
    photon_points._offsets3d = (photon_x[mask], photon_y[mask], photon_z[mask])
    photon_points.set_facecolor(viridis(norm(photon_time[mask])))
    time_text.set_text('Time = {:.8f} s'.format(time[frame]))
    photon_count_text.set_text('PM activés: {}'.format(np.sum(mask)))
    return line, point, photon_points, time_text, photon_count_text

ani = FuncAnimation(fig, update, frames=len(time), init_func=init, blit=True, interval=10)
#commentaire en dessous a retirer pour voir en fenêtre et pas en gif. rajouter un commentaire à ani.save pour gagner du temps
writer = PillowWriter(fps=30)
ani.save('visu_example.gif', writer=writer)
plt.legend()
#plt.show()
